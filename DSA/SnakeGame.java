
import java.util.*;

class SnakeGame {

    HashMap<String,int[]> dirMap = new HashMap<>();
    
    class Cell{
        int row;
        int col;
        Cell(int row,int col){
            this.row = row;
            this.col = col;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            Cell other = (Cell) obj;
            return row == other.row && col == other.col;
        }
        @Override
        public int hashCode(){
            return Objects.hash(row,col);
        }
    }

    int width;
    int height;
    int score;
    boolean gameOver;
    int[][] food;
    int foodIndex = 0;
    ArrayDeque<Cell> snakeBody;
    HashSet<Cell> snakeSet;


    public SnakeGame(int width, int height, int[][] food) {
        this.height = height;
        this.width = width;
        this.score = 0;
        this.gameOver = false;
        snakeBody = new ArrayDeque<>();
        snakeSet = new HashSet<>();

        this.food = food;
        this.foodIndex = 0;

        snakeBody.add(new Cell(0,0));
        snakeSet.add(new Cell(0,0));

        dirMap.put("U", new int[]{-1, 0});
        dirMap.put("D", new int[]{1, 0});
        dirMap.put("L", new int[]{0, -1});
        dirMap.put("R", new int[]{0, 1});

        
    }
    public int move (String direction) {

        if(this.gameOver) return -1;
        
        int[] currentDirection = dirMap.get(direction);
        Cell snakeHead = snakeBody.peekLast();

        int newRow = snakeHead.row + currentDirection[0];
        int newCol = snakeHead.col + currentDirection[1];

        if(newRow < 0 || newCol < 0 || newRow >= this.height || newCol >= this.width){
            score = -1;
            this.gameOver = true;
            return -1;
        }

        Cell newHead = new Cell(newRow,newCol);

        boolean eatingFood = false;
        if(foodIndex < food.length && food[foodIndex][0] == newHead.row && food[foodIndex][1] == newHead.col){
            eatingFood = true;
        }

        if(!eatingFood) {
            Cell tail = snakeBody.removeFirst();
            snakeSet.remove(tail);
        }

        if(snakeSet.contains(newHead)) {
            gameOver = true;
            return -1;
        }

        snakeBody.addLast(newHead);
        snakeSet.add(newHead);

        if(eatingFood) {
            foodIndex++;
            score++;
        }

        return score;
        
    }

    public static void main(String[] args) {
        SnakeGame game = new SnakeGame(3, 2,   new int[][]{{1, 2}, {0, 1}});


        System.out.println(game.move("R")); // move to (0,1), no food there -> score 0
        System.out.println(game.move("D")); // move to (1,1), no food there -> score 0
        System.out.println(game.move("R")); // move to (1,2), food here! -> score 1, snake grows
        System.out.println(game.move("U")); // move to (0,2), no food -> score 1
        System.out.println(game.move("L")); // move to (0,1), food here! -> score 2, snake grows
        System.out.println(game.move("U")); // moves out of bounds -> game over, return -1

    }
    
}

